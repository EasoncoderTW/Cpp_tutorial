# Compile Tips for Cpp

## Using g++
正常來說，可以用以下的方式進行編譯
```shell
g++ 需要被編譯的檔案(.cpp) [-o 編譯後的執行檔名稱(.exe)]
```
如果不給予`-o`參數的話，則預設輸出檔案的名稱為`a.exe`

eg.
```shell
g++ .\main.cpp -o .\main.exe
.\main.exe
```

## File system
### path (in Windows)
- 移動現在目錄位置 `cd`
- 往前一層 `cd ..`
- 列出該目錄下的檔案或資料夾 `dir`

### path (in Linux)
- 移動現在目錄位置 `cd`
- 往前一層 `cd ..`
- 列出該目錄下的檔案或資料夾 `ls [-a|-al]`