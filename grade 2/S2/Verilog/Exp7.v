// 閘級描述的四位元漣波進位加法器模組
module experiment7 (
    output [3:0] Sum,  // 輸出和的四個位元
    output Cout,       // 輸出進位位元
    input [3:0] A, B,  // 兩個四位元數字的輸入
    input S,           // 減法或加法
    input Cin,         // Cin
    output Neg         // 當結果為負時為 1
);

wire [3:0] NB;
wire [3:0] result;
wire C1, C2, C3;
wire B_neg;

// 計算 B 的補數
assign NB = (S) ? (~B + 1) : B; // 根據 S 的值選擇正確的補數

// 實例化全加法器鏈
full_adder FA0 (result[0], C1, A[0], NB[0], Cin),
           FA1 (result[1], C2, A[1], NB[1], C1),
           FA2 (result[2], C3, A[2], NB[2], C2),
           FA3 (result[3], Cout, A[3], NB[3], C3);

// 計算結果是否為負
assign B_neg = S & (A < B);

// 如果結果為負，取二補數
assign Sum = (B_neg) ? ~result + 1 : result;

// 計算 Neg
assign Neg = S & (A < B);

endmodule

// 半加法器的描述
module half_adder (
    output S, C,     // 和及進位位元的輸出
    input x, y       // 兩個輸入位元
);

assign S = x ^ y;   // 和的計算
assign C = x & y;   // 進位的計算

endmodule

// 全加法器的描述
module full_adder (
    output S, C,     // 和及進位位元的輸出
    input x, y, z    // 三個輸入位元
);

wire S1, C1, C2;

// 實例化半加法器
half_adder HA1 (S1, C1, x, y);
half_adder HA2 (S, C2, S1, z);
assign C = C2 | C1; // 進位的計算

endmodule
