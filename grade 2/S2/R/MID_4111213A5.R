#第一題
#1.1
星期<-c("星期一","星期二","星期三","星期四","星期五")
本週台股加權指數漲跌幅<-c(300,500,-560,250,-128)
names(本週台股加權指數漲跌幅)<-星期 # 合併
本週台股加權指數漲跌幅

#1.2
上週與本週資料<-c(1000,800)
台股上週和本周交易量<-matrix(上週與本週資料,nrow=1,byrow = TRUE)
rownames(台股上週和本周交易量)<-c("台股加權指數總成交量") # 改row名稱
colnames(台股上週和本周交易量)<-c("上週成交量(萬張)","本週成交量(萬張)") # 改col名稱
台股上週和本周交易量

#1.3
股市大盤解析 <- c("強勁反彈","後勢看漲","高檔震盪","指數新高")
大盤操作評論 <- c("大量買進持有","少量賣出獲利","持續觀查不動","持股比例提高")
操作評論來源 <- c("股達人","股go","潮股網","股動前潮")
股市大盤評論 <- data.frame(股市大盤解析,大盤操作評論,操作評論來源) # 合併放入dataframe
股市大盤評論

#第二題
台股加權指數列表<-list(本週台股加權指數漲跌幅,台股上週和本周交易量,股市大盤評論) # 合併成list
names(台股加權指數列表)<-c("台股大盤本週漲跌幅","台股兩週成交量","台股評論")
台股加權指數列表

#第三題
資料提供<-"亂談股市" # 新增一筆資料
台股加權指數列表<-c(台股加權指數列表,資料提供來源=資料提供)
台股加權指數列表

#第四題
numbers <- c(10, 24, 5, 30, 1)
n24 <- which(numbers == 24) # 找出24的位置
if (length(n24) == 0) {
  print('24所在的位置位於數字資料中第幾個: 0')
} else {
  message1 <- paste("24所在的位置位於數字資料中第幾個:", (n24))
  print(message1)
  message2 <- paste("比24大的數字有幾個:", length(numbers[numbers > 24])) 
  print(message2)
  message3 <- paste("比24小的數字有幾個:", length(numbers[numbers < 24]))
  print(message3)
}

#第五題
numbers <- c(50, 6, 23, 99, 1, 25) 
numbers<-sort(numbers) #由小到大排序後存回numbers
print(paste("SecMax:",numbers[5])) # 印出倒數第二個(就是第二大的值)

#第六題
num <- as.integer(readline(prompt = "請輸入一個五位數的整數:"))

# 分別取出每一位數字
digit1 <- num %/% 10000 # %/% 取整數的部分
digit2 <- num %% 10000 %/% 1000 # %% 取餘數的部分
digit3 <- num %% 1000 %/% 100
digit4 <- num %% 100 %/% 10
digit5 <- num %% 10

# 判斷是否為迴文
if (digit1 == digit5 & digit2 == digit4) {
  print("迴文")
} else {
  print("不是迴文")
}

#第七題
Electricity_bill <- function(kwh, month = 7, business = 0) {
  summer <- c(month >= 6 && month <= 9)  # 判斷是否夏季月份
  total <- 0 # 初始化總電費
  
  # 非商業用戶
  if (business == FALSE) {
    if (kwh > 0) {
      total <- total + ifelse(kwh < 120, kwh, 120) * 1.63 # 120以下
      kwh <- kwh - 120
    }
    if (kwh > 0) {
      diff <- 330 - 120
      total <- total + ifelse(kwh < diff, kwh, diff) * ifelse(summer, 2.38, 2.10) # 121-330
      kwh <- kwh - diff
    }
    if (kwh > 0) {
      diff <- 500 - 330
      total <- total + ifelse(kwh < diff, kwh, diff) * ifelse(summer, 3.52, 2.89) # 331-500
      kwh <- kwh - diff
    }
    if (kwh > 0) {
      diff <- 700 - 500
      total <- total + ifelse(kwh < diff, kwh, diff) * ifelse(summer, 4.80, 3.94) # 501-700
      kwh <- kwh - diff
    } 
    if (kwh > 0) {
      diff <- 1000 - 700
      total <- total + ifelse(kwh < diff, kwh, diff) * ifelse(summer, 5.66, 4.60) # 701-1000
      kwh <- kwh - diff
    }    
    if (kwh > 0) {
      total <- total + kwh * ifelse(summer, 6.41, 5.03) # 1001以上
    } 
  } else {
    # 商業用戶
    if (kwh > 0) {
      total <- total + ifelse(kwh < 330, kwh, 330) * ifelse(summer, 2.53, 2.12) # 330以下
      kwh <- kwh - 330
    }
    if (kwh > 0) {
      diff <- 700 - 300
      total <- total + ifelse(kwh < diff, kwh, diff) * ifelse(summer, 3.55, 2.91) # 301-700
      kwh <- kwh - diff
    }
    if (kwh > 0) {
      diff <- 1500 - 700
      total <- total + ifelse(kwh < diff, kwh, diff) * ifelse(summer, 4.25, 3.44) # 701-1500
      kwh <- kwh - diff
    }    
    if (kwh > 0) {
      total <- total + kwh * ifelse(summer, 6.43, 5.05) # 1500以上
    }    
  }
  print(round(total)) # 四捨五入並印出總電費
}

Electricity_bill(800, 7, 0) # 輸入800度，7月份，非商業用戶

