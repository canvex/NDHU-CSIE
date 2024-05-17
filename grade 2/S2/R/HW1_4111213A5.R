球魔方 <- function(n){
  line <- matrix(c(1,2,3,4,5,6,7,8,9,1,4,7,2,5,8,3,6,9,1,5,9,3,5,7), nrow=8, ncol=3, byrow=TRUE) #中獎連線方式
  print("==================")
  count <- 0 # 初始化 count 變數
  result <- c(未中獎 = 0, 中獎 = 0) # 初始化結果向量
  for (i in 1:n) {
    print(i)
    print("預設中獎:")
    # 生成電腦預設中獎矩陣
    vec <- rep(NA, 9)
    vec[line[sample(1:8, 1), ]] <- "O"
    mat <- matrix(vec, nrow=3, byrow=TRUE)
    print(mat)
    print("玩家連線:")
    # 生成玩家中獎矩陣
    vec <- rep(NA, 9)
    vec[sample(1:9, 3)] <- "O"
    mat2 <- matrix(vec, nrow=3, byrow=TRUE)
    print(mat2)
    if (identical(mat, mat2)) {
      print("結果:中獎")
      count <- count + 1
    } else {
      print("結果：再一次")
    }
  }
  print("==================")
  result <- c(未中獎 = n - count, 中獎 = count)  # 統計結果向量
  print(result)
  barplot(result, main = "球魔方中獎統計圖表") # 繪製統計圖表
}

球魔方(100000) # 想要執行的次數

