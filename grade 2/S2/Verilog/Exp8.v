module DFF(
    input wire clk,   // 时钟信号
    input wire D,     // 数据输入
    output reg Q      // 输出数据
);
    always @(posedge clk) begin
        Q <= D;
    end
endmodule

module E8(
    input wire clk,        // 时钟信号
    input wire load,       // 加载信号
    input wire mode,       // 模式控制信号
    input wire [3:0] data, // 要加载的数据
    output wire [3:0] ring, // Ring Counter输出数据
    output wire [3:0] johnson // Johnson Counter输出数据
);

// 定义线以存储D触发器的输出
wire [3:0] ring_ff_out;
wire [3:0] johnson_ff_out;

// 定义用于连接D触发器的线
wire [3:0] ring_dff_d;
wire [3:0] johnson_dff_d;

// 实例化Ring Counter的D触发器
DFF ring_dff0 (.clk(clk), .D(ring_dff_d[0]), .Q(ring_ff_out[0]));
DFF ring_dff1 (.clk(clk), .D(ring_dff_d[1]), .Q(ring_ff_out[1]));
DFF ring_dff2 (.clk(clk), .D(ring_dff_d[2]), .Q(ring_ff_out[2]));
DFF ring_dff3 (.clk(clk), .D(ring_dff_d[3]), .Q(ring_ff_out[3]));

// 实例化Johnson Counter的D触发器
DFF johnson_dff0 (.clk(clk), .D(johnson_dff_d[0]), .Q(johnson_ff_out[0]));
DFF johnson_dff1 (.clk(clk), .D(johnson_dff_d[1]), .Q(johnson_ff_out[1]));
DFF johnson_dff2 (.clk(clk), .D(johnson_dff_d[2]), .Q(johnson_ff_out[2]));
DFF johnson_dff3 (.clk(clk), .D(johnson_dff_d[3]), .Q(johnson_ff_out[3]));

// 控制Ring Counter和Johnson Counter的输入
assign ring_dff_d[0] = load ? data[0] : ring_ff_out[3];
assign ring_dff_d[1] = load ? data[1] : ring_ff_out[0];
assign ring_dff_d[2] = load ? data[2] : ring_ff_out[1];
assign ring_dff_d[3] = load ? data[3] : ring_ff_out[2];

assign johnson_dff_d[0] = load ? data[0] : ~johnson_ff_out[3];
assign johnson_dff_d[1] = load ? data[1] : johnson_ff_out[0];
assign johnson_dff_d[2] = load ? data[2] : johnson_ff_out[1];
assign johnson_dff_d[3] = load ? data[3] : johnson_ff_out[2];

// 根据模式输出适当的计数器值
assign ring = (mode == 0) ? ring_ff_out : 4'b0000;
assign johnson = (mode == 1) ? johnson_ff_out : 4'b0000;

endmodule