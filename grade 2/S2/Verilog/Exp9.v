module decoder_2to4 (
    input InSwitch,
    output reg EN0, EN1
);
    always @(*) begin
        case (InSwitch)
            1'b0: begin
                EN0 = 1'b1;
                EN1 = 1'b0;
            end
            1'b1: begin
                EN0 = 1'b0;
                EN1 = 1'b1;
            end
            default: begin
                EN0 = 1'b0;
                EN1 = 1'b0;
            end
        endcase
    end
endmodule

module decoder_3to8 (
    input EN,
    input [2:0] InSwitch,
    output reg [7:0] outLED
);
    always @(*) begin
        if (EN) begin
            case (InSwitch)
                3'b000: outLED = 8'b00000001;
                3'b001: outLED = 8'b00000010;
                3'b010: outLED = 8'b00000100;
                3'b011: outLED = 8'b00001000;
                3'b100: outLED = 8'b00010000;
                3'b101: outLED = 8'b00100000;
                3'b110: outLED = 8'b01000000;
                3'b111: outLED = 8'b10000000;
                default: outLED = 8'b00000000;
            endcase
        end else begin
            outLED = 8'b00000000;
        end
    end
endmodule

module Exp9 (
    input [3:0] InSwitch,
    output [15:0] outLED
);
    wire EN0, EN1;
    wire [7:0] outLED0, outLED1;

    // Instantiate the 2-to-4 decoder used as 1-to-2 decoder
    decoder_2to4 d2to4 (.InSwitch(InSwitch[3]), .EN0(EN0), .EN1(EN1));

    // Instantiate the 3-to-8 decoders
    decoder_3to8 d3to8_0 (.EN(EN0), .InSwitch(InSwitch[2:0]), .outLED(outLED0));
    decoder_3to8 d3to8_1 (.EN(EN1), .InSwitch(InSwitch[2:0]), .outLED(outLED1));

    // Combine the outputs to form the final 16 outputs
    assign outLED = ~{outLED1, outLED0};

endmodule