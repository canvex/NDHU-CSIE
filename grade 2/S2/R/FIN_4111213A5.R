# 第一題
library(rpart)
library(rpart.plot)
library(rattle)
library(RColorBrewer)

# 讀取 CSV 檔案
核准貸款 <- read.csv("C:/Users/brian/Documents/Programming/R/核准貸款.csv", header=TRUE, sep=',')
print(核准貸款)

# 建立決策樹模型
核准資料樹 <- rpart(核可貸款 ~ ., data=核准貸款, method="class", control=rpart.control(minsplit=5))

# 繪製決策樹
fancyRpartPlot(核准資料樹)

# 新資料進行預測
newdata <- data.frame(年紀="年輕", 工作="無", 房子="無", 信用="好")
prediction <- predict(核准資料樹, newdata, type="class")
print(prediction)


# 第二題

# 讀取 CSV 檔案
Hyper <- read.csv("C:/Users/brian/Documents/Programming/R/Dataset.csv", header=TRUE)

# 檢查前幾行資料
head(Hyper)

# 新增高血壓欄位
Hyper$Hypertension <- ifelse(Hyper$SBP..mmHg. > 140, 1, 0)

# 輸出 Hyper 資料框
print(Hyper)

# 計算高血壓人數
hypertension_count <- sum(Hyper$Hypertension)
cat("高血壓人數:", hypertension_count)



# 第三題
library(tm)
library(magrittr)

# 讀取文本檔案
interview <- readLines("C:/Users/brian/Documents/Programming/R/Elon_Musk_interview.txt")

# 建立文本語料庫並進行處理
corpus <- VCorpus(VectorSource(interview)) %>%
  tm_map(stripWhitespace) %>%
  tm_map(content_transformer(tolower)) %>%
  tm_map(removeNumbers) %>%
  tm_map(removePunctuation) %>%
  tm_map(removeWords, stopwords("english"))

# 建立詞彙矩陣並計算詞頻
tdm <- TermDocumentMatrix(corpus) %>%
  as.matrix() %>%
  rowSums() %>%
  sort(decreasing = TRUE) %>%
  head()

# 將詞頻轉換為資料框
tdmdf <- data.frame(freq=tdm)
print(tdmdf)

# 繪製前六多詞彙長條圖
bf <- barplot(tdmdf$freq, xlab='word', ylab='freq', names.arg=rownames(tdmdf), main='前六多詞彙長條圖', col="orange")

# 在長條圖上添加數值標籤
text(bf, tdmdf$freq, labels=tdmdf$freq, pos=1)
