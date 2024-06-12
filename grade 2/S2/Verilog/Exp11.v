module Exp11 (
    input wire clk,           // 時鐘信號
    input wire [15:0] din,    // 16 位並行輸入數據
    output wire [15:0] dout   // 16 位並行輸出數據
);
    wire serial_data;         // 串行數據連接線

    // 發射器模組實例化，負責將並行數據轉換為串行數據
    Transmitter tx (
        .clk(clk), 
        .din(din), 
        .dout(serial_data)
    );

    // 接收器模組實例化，負責將串行數據轉換為並行數據
    Receiver rx (
        .clk(clk), 
        .din(serial_data), 
        .dout(dout)
    );
endmodule

module TFF (
    input wire clk,    // 時鐘信號
    input wire T,      // T 觸發器輸入信號
    output reg Q       // 輸出信號
);
    // 在時鐘信號的負緣觸發
    always @(negedge clk) begin
        if (T)           // 當 T 為高電平時
            Q <= ~Q;     // 翻轉輸出 Q
    end
endmodule

module Counter16 (
    input wire clk,        // 時鐘信號
    output wire [3:0] count // 4 位計數值輸出
);
    // 4 個 T-FF 實例化，用於計數
    wire [3:0] tff_out;
    wire [3:0] tff_enable;

    // 第一個 T-FF 的使能信號常為高
    assign tff_enable[0] = 1'b1;

    // 後續 T-FF 的使能信號取決於前一個 T-FF 的輸出
    assign tff_enable[1] = tff_out[0];
    assign tff_enable[2] = tff_out[0] & tff_out[1];
    assign tff_enable[3] = tff_out[0] & tff_out[1] & tff_out[2];

    // 實例化 T-FF 模組
    TFF tff0 (.clk(clk), .T(tff_enable[0]), .Q(tff_out[0]));
    TFF tff1 (.clk(clk), .T(tff_enable[1]), .Q(tff_out[1]));
    TFF tff2 (.clk(clk), .T(tff_enable[2]), .Q(tff_out[2]));
    TFF tff3 (.clk(clk), .T(tff_enable[3]), .Q(tff_out[3]));

    // 將 T-FF 的輸出連接到計數值輸出
    assign count = tff_out;
endmodule

module Mux16to1 (
    input wire [15:0] in,  // 16 位並行輸入數據
    input wire [3:0] sel,  // 4 位選擇信號
    output wire out        // 輸出信號
);
    assign out = in[sel];  // 根據選擇信號選擇並輸出相應的輸入信號
endmodule

module Demux1to16 (
    input wire in,          // 輸入信號
    input wire [3:0] sel,   // 4 位選擇信號
    output wire [15:0] out  // 16 位並行輸出數據
);
    // 根據選擇信號將輸入信號分配到相應的輸出線
    assign out = (1 << sel) & {16{in}};
endmodule

module Transmitter (
    input wire clk,         // 時鐘信號
    input wire [15:0] din,  // 16 位並行輸入數據
    output wire dout        // 串行輸出數據
);
    wire [3:0] count;       // 4 位計數值

    // 計數器模組實例化，生成計數值
    Counter16 counter (
        .clk(clk), 
        .count(count)
    );

    // 多路選擇器模組實例化，根據計數值選擇輸出相應的數據位
    Mux16to1 mux (
        .in(din), 
        .sel(count), 
        .out(dout)
    );
endmodule

module Receiver (
    input wire clk,         // 時鐘信號
    input wire din,         // 串行輸入數據
    output wire [15:0] dout // 16 位並行輸出數據
);
    wire [3:0] count;       // 4 位計數值

    // 計數器模組實例化，生成計數值
    Counter16 counter (
        .clk(clk), 
        .count(count)
    );

    // 解復用器模組實例化，根據計數值分配輸入信號到相應的輸出線
    Demux1to16 demux (
        .in(din), 
        .sel(count), 
        .out(dout)
    );
endmodule
