module decoder_3to8 (
    input [1:0] InSwitch,
    output reg [3:0] EN
);
    always @(*) begin
        case (InSwitch)
            2'b00: EN = 4'b0001;
            2'b01: EN = 4'b0010;
            2'b10: EN = 4'b0100;
            2'b11: EN = 4'b1000;
            default: EN = 4'b0000;
        endcase
    end
endmodule

module decoder_2to4 (
    input EN,
    input [1:0] InSwitch,
    output reg [3:0] outLED
);
    always @(*) begin
        if (EN) begin
            case (InSwitch)
                2'b00: outLED = 4'b0001;
                2'b01: outLED = 4'b0010;
                2'b10: outLED = 4'b0100;
                2'b11: outLED = 4'b1000;
                default: outLED = 4'b0000;
            endcase
        end else begin
            outLED = 4'b0000;
        end
    end
endmodule

module Exp9_1 (
    input [3:0] InSwitch,
    output [15:0] outLED
);
    wire [3:0] EN;
    wire [3:0] outLED0, outLED1, outLED2, outLED3;

    // Instantiate the 3-to-8 decoder used as 2-to-4 decoder
    decoder_3to8 d3to8 (.InSwitch(InSwitch[3:2]), .EN(EN));

    // Instantiate the 2-to-4 decoders
    decoder_2to4 d2to4_0 (.EN(EN[0]), .InSwitch(InSwitch[1:0]), .outLED(outLED0));
    decoder_2to4 d2to4_1 (.EN(EN[1]), .InSwitch(InSwitch[1:0]), .outLED(outLED1));
    decoder_2to4 d2to4_2 (.EN(EN[2]), .InSwitch(InSwitch[1:0]), .outLED(outLED2));
    decoder_2to4 d2to4_3 (.EN(EN[3]), .InSwitch(InSwitch[1:0]), .outLED(outLED3));

    // Combine the outputs to form the final 16 outputs
    assign outLED = ~{outLED3, outLED2, outLED1, outLED0};

endmodule