module Exp10(swA, swB, Cin, out1, out0);
    input [3:0] swA, swB;  // 4位元輸入 A 和 B
    input Cin;            // 輸入進位
    output out1;          // 最高位元進位輸出
    output [3:0] out0;    // 9進制輸出

    wire [3:0] sum1, sum2;
    wire CoutTemp;

    // 使用兩個4位元加法器來進行BCD和9進制的計算
    rippleCarry_4bitAdder adder1(swA, swB, Cin, CoutTemp, sum1);
    radix9_Adder adder2(sum1, CoutTemp, sum2, out1);
    assign out0 = sum2;
endmodule

module radix9_Adder(in, Cin, out, out1);
    input [3:0] in;       // 4位元輸入
    input Cin;            // 輸入進位
    output [3:0] out;     // 4位元輸出
    output out1;          // 最高位元進位輸出

    wire [3:0] correctedSum;
    wire a3;

    // 計算修正後的和
    assign correctedSum = in + Cin;
    // 當和大於或等於9時，進位為1
    assign a3 = (correctedSum >= 4'd9) ? 1'b1 : 1'b0;
    // 如果和大於或等於9，則輸出和減去9，否則直接輸出和
    assign out = (correctedSum >= 4'd9) ? (correctedSum - 4'd9) : correctedSum;
    assign out1 = a3;
endmodule

module rippleCarry_4bitAdder(inA, inB, Cin, out1, sum);
    input [3:0] inA, inB;  // 4位元輸入 A 和 B
    input Cin;             // 輸入進位
    output out1;           // 最高位元進位輸出
    output [3:0] sum;      // 4位元和輸出

    wire [3:0] sumS, CoutS;

    // 四個全加器串接組成4位元漣波進位加法器
    fullAdder adder0(inA[0], inB[0], Cin, sumS[0], CoutS[0]);
    fullAdder adder1(inA[1], inB[1], CoutS[0], sumS[1], CoutS[1]);
    fullAdder adder2(inA[2], inB[2], CoutS[1], sumS[2], CoutS[2]);
    fullAdder adder3(inA[3], inB[3], CoutS[2], sumS[3], CoutS[3]);

    assign sum = sumS;
    assign out1 = CoutS[3];
endmodule

module halfAdder(inA, inB, sum, out1);
    input inA, inB;   // 單位元輸入 A 和 B
    output sum, out1; // 單位元和輸出及進位輸出

    // 半加器
    xor(sum, inA, inB);
    and(out1, inA, inB);
endmodule

module fullAdder(inA, inB, Cin, sum, out1);
    input inA, inB, Cin; // 單位元輸入 A、B 和進位
    output sum, out1;    // 單位元和輸出及進位輸出

    wire sum1, sum2, Cout1, Cout2;

    // 兩個半加器串接組成全加器
    halfAdder ha1(inA, inB, sum1, Cout1);
    halfAdder ha2(sum1, Cin, sum2, Cout2);

    assign sum = sum2;
    or(out1, Cout1, Cout2);
endmodule
