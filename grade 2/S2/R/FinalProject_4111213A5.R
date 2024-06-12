# 讀取數據
data <- read.csv("整理後資料.csv", header = TRUE, stringsAsFactors = FALSE)

# 1.各月份發生車禍統計
accident_months <- data$發生月份
# 計算每月車禍次數
monthly_accidents <- table(accident_months)
barplot(monthly_accidents, 
        main = "各月份發生車禍統計",
        xlab = "月份",
        ylab = "車禍次數",
        col = "blue")


# 2.寒暑假及非寒暑假車禍次數比較
# 計算1、7、8月份的車禍次數
summer_accidents <- sum(accident_months == 1 | accident_months == 7 | accident_months == 8)
# 計算其他月份的車禍次數
non_summer_accidents <- sum(accident_months != 1 & accident_months != 7 & accident_months != 8)
par(mfrow=c(1,2))  # 設置為一行兩列的布局
# 提取1、7、8月份的車禍資料
summer_months <- accident_months %in% c(1, 7, 8)
accident_summer <- accident_months[summer_months]
# 計算1、7、8月份的車禍次數
monthly_accidents_summer <- table(accident_summer)
# 繪製1、7、8月份的條狀圖
barplot(monthly_accidents_summer, 
        main = "寒暑假車禍次數",
        xlab = "月份",
        ylab = "車禍次數",
        col = "blue")
# 提取非1、7、8月份的車禍資料
accident_non_summer <- accident_months[!summer_months]
# 計算非1、7、8月份的車禍次數
monthly_accidents_non_summer <- table(accident_non_summer)
# 繪製非1、7、8月份的條狀圖
barplot(monthly_accidents_non_summer, 
        main = "非寒暑假車禍次數",
        xlab = "月份",
        ylab = "車禍次數",
        col = "red")
# 提取發生月份欄位資料
accident_months <- data$發生月份


# 3.季節是否影響車禍
# 季節判斷
get_season <- function(month) {
  if (month %in% 3:5) {
    return("春")
  } else if (month %in% 6:8) {
    return("夏")
  } else if (month %in% 9:11) {
    return("秋")
  } else {
    return("冬")
  }
}
# 將月份轉換為季節
accident_seasons <- sapply(accident_months, get_season)
# 計算每個季節的百分比
seasonal_accidents_percentage <- prop.table(seasonal_accidents) * 100
pie(seasonal_accidents_percentage, 
    main = "各季節車禍次數占比",
    col = rainbow(length(seasonal_accidents_percentage)),
    labels = paste(names(seasonal_accidents_percentage), "\n", round(seasonal_accidents_percentage, 1), "%"),
    cex = 0.8)


# 4.一天中哪個時段最常發生車禍
# 提取發生時間欄位資料
accident_hours <- data$發生時間
# 計算各時段中的車禍次數
hourly_accidents <- table(accident_hours)
# 繪製條狀圖
barplot(hourly_accidents, 
        main = "各時段車禍次數分佈",
        xlab = "時段",
        ylab = "車禍次數",
        col = "blue")


# 5.全台縣市車禍次數排名
# 提取發生縣市欄位資料
accident_cities <- data$發生縣市
# 計算各縣市中的車禍次數
city_accidents <- table(accident_cities)
# 將車禍次數由高到低排序
sorted_city_accidents <- sort(city_accidents, decreasing = TRUE)
# 建立顏色向量，用於條狀圖
colors <- rainbow(length(sorted_city_accidents))
# 繪製條狀圖
barplot(sorted_city_accidents, 
        main = "各縣市車禍次數分佈",
        xlab = "縣市",
        ylab = "車禍次數",
        col = "purple",
        names.arg = names(sorted_city_accidents),
        las = 2)


# 6.最常在哪裡發生車禍Top10
# 提取事故位置子類別欄位資料
accident_location <- data$事故位置子類別名稱
# 計算各道路類別中的車禍次數
road_accidents <- table(accident_location)
# 將車禍次數由高到低排序
sorted_road_accidents <- sort(road_accidents, decreasing = TRUE)
# 取前10個類別
top_10_road_accidents <- sorted_road_accidents[1:10]
# 建立顏色向量，用於條狀圖
colors <- rainbow(length(top_10_road_accidents))
# 繪製條狀圖
barplot(top_10_road_accidents, 
        main = "前10道路類別車禍次數分佈",
        xlab = "道路類別",
        ylab = "車禍次數",
        col = colors,
        names.arg = names(top_10_road_accidents),
        las = 2)

# 7.肇事原因Top10
# 提取肇因研判子類別名稱欄位資料
cause_subcategory <- data$肇因研判子類別名稱
# 計算各肇因研判子類別中的車禍次數
cause_accidents <- table(cause_subcategory)
# 取前10個肇因研判子類別
top_10_cause_accidents <- head(sort(cause_accidents, decreasing = TRUE), 10)
# 建立顏色向量，用於圓餅圖
colors <- rainbow(length(top_10_cause_accidents))
# 計算百分比
percentage <- prop.table(top_10_cause_accidents) * 100
# 繪製圓餅圖
pie(top_10_cause_accidents, 
    main = "前10筆肇因研判子類別車禍次數分佈",
    col = colors,
    labels = paste(names(top_10_cause_accidents), "\n", sprintf("%.1f%%", percentage)))


# 8.死亡人數與受傷人數統計
# 提取死亡人數和受傷人數欄位資料
deaths <- data$死亡人數
injuries <- data$受傷人數
# 計算死亡人數和受傷人數的總和
total_deaths <- sum(deaths, na.rm = TRUE)
total_injuries <- sum(injuries, na.rm = TRUE)
# 建立數值向量
counts <- c(total_deaths, total_injuries)
# 建立顏色向量，用於條狀圖
colors <- c("red", "blue")
# 建立標籤向量
names <- c("死亡人數", "受傷人數")
# 繪製條狀圖
barplot(counts, 
        main = "死亡人數與受傷人數",
        names.arg = names,
        col = colors,
        ylab = "人數",
        ylim = c(0, max(counts) * 1.1),
        beside = TRUE) # beside = TRUE 表示將兩個值條放在一起

# 在條狀圖上顯示數字
text(x = 1:length(counts), y = counts, labels = counts, pos = 1, cex = 0.8, col = "black")


# 9.當事者是駕駛什麼類型的車
# 提取當事者車種欄位資料
vehicle_types <- data$當事者車種
# 計算各車種的數量
vehicle_counts <- table(vehicle_types)
# 取前10筆數量最多的車種
top_10_vehicle_counts <- head(sort(vehicle_counts, decreasing = TRUE), 10)
# 建立顏色向量，用於條狀圖
colors <- rainbow(length(top_10_vehicle_counts))
# 繪製條狀圖
barplot(top_10_vehicle_counts, 
        main = "當事者車種分佈",
        col = colors,
        names.arg = names(top_10_vehicle_counts),
        ylab = "數量",
        las = 2) # 使用直式標籤
# 在每個值條頂部顯示數字
text(x = 1:10, y = top_10_vehicle_counts, labels = top_10_vehicle_counts, pos = 3, cex = 0.8, col = "black")


# 10.是否使用3C產品
# 提取是否使用3C產品欄位資料
using_3C <- data$是否使用3C產品
# 計算各類別的數量
using_3C_counts <- table(using_3C)
# 將數量轉換為百分比
using_3C_percent <- prop.table(using_3C_counts) * 100
# 建立顏色向量，用於圓餅圖
colors <- rainbow(length(using_3C_counts))
# 繪製圓餅圖
pie(using_3C_counts, 
    main = "是否使用3C產品分佈",
    col = colors,
    labels = paste(names(using_3C_counts), "\n", sprintf("%.1f%%", using_3C_percent)))
