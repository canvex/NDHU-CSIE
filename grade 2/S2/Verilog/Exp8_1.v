module Exp8_1 (
    input wire clk,         // 時鐘輸入
    output wire [3:0] out   // 4位輸出，用於表示計數器的值
);

    wire d0, d1, d2, d3;
    wire q0, q1, q2, q3;
    
    // 輸出連接到正反器的Q輸出
    assign out = {q3, q2, q1, q0};

    // 當計數器達到 6 (0110) 時，所有輸出變為 0
    wire reset = (q3 == 1'b0 && q2 == 1'b1 && q1 == 1'b1 && q0 == 1'b0);

    // 計算 D0, D1, D2 的值，當reset時，所有D輸入變為0
    assign d0 = reset ? 1'b0 : ~q0;
    assign d1 = reset ? 1'b0 : q0 ^ q1;
    assign d2 = reset ? 1'b0 : (q0 & q1) ^ q2;
    assign d3 = reset ? 1'b0 : (q0 & q1 & q2) ^ q3;

    // D型正反器實現
    DFF dff0 (.clk(clk), .d(d0), .q(q0));
    DFF dff1 (.clk(clk), .d(d1), .q(q1));
    DFF dff2 (.clk(clk), .d(d2), .q(q2));
    DFF dff3 (.clk(clk), .d(d3), .q(q3));

endmodule

// D型正反器模組
module DFF (
    input wire clk,
    input wire d,
    output reg q
);
    always @(posedge clk) begin
        q <= d;
    end
endmodule
