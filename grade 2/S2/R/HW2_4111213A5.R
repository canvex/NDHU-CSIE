library("rvest")

# 讀取網頁
url <- 'https://tw.stock.yahoo.com/d/s/dividend_2330.html'
data <- read_html(url)

# 抓取所有包含資料的節點
tables <- html_nodes(data, '.M\\(0\\)')

# 選擇第一個表格
table <- tables[1]

# 抓取所有列
rows <- html_nodes(table, 'li')

# 初始化變數
發放期間 <- c()
現金股利 <- c()

# 從每一列抓取資料
for (i in 1:length(rows)) {
  cols <- html_nodes(rows[i], 'div')
  year <- html_text(cols[2])
  cash <- html_text(cols[5])
  
  # 如果年分不為空，則加入向量
  if(year != '') {
    發放期間 <- c(發放期間, year)
    現金股利 <- c(現金股利, cash)
  }
}

# 處理現金股利數據
現金股利[現金股利 == '-'] <- '0'
現金股利 <- as.numeric(現金股利)

# 畫長條圖
bp <- barplot(現金股利, names.arg = 發放期間, main = '台積電現金股利資料長條圖', xlab = '發放期間', ylab = '現金股利', col = 'skyblue')

# 在長條圖上標示數值
text(bp, 現金股利, labels = 現金股利, pos = 1)

# 計算並輸出平均現金股利
average <- sum(現金股利) / length(現金股利)
cat('平均現金股利:', average)
