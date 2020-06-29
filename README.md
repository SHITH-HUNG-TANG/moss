# -moss-

## Introduction
這份程式住主要來自[MOSS](http://theory.stanford.edu/~aiken/moss/)，網站中有說明如何安裝及說明，然而在此還增加了一些輔助性的程式，如合併相同學號的程式等等。

## Dependencies
|Name|
|----|
|python|
|Strawberry Perl|

## Usage Pre-processing

### 1.先將學生資料夾解壓縮

<p align="center">
    <img src="img/PreFile1.png">
</p>

### 2.將每位學生需要比較的內容.h/.cpp留下(只需處理.h/.cpp、其他副檔名可忽略)

<p align="center">
    <img src="img/PreFile2.png">
</p>

### 3.將每位學生需要比較的內容.h/.cpp留下(只需處理.h/.cpp、其他副檔名可忽略)

<p align="center">
    <img src="img/PreFile3.png">
</p>

### 4.將所有學生處理完後，統一複製至 `${Path_to_mergeFile}/input` 裡

<p align="center">
    <img src="img/PreFile4.png", width="480">
    <img src="img/PreFile5.png", width="480">
</p>

### 5.執行`python ${Path_to_mergeFile}/run.py`

### 6.結果會輸出在 `${Path_to_mergeFile}/output`

<p align="center">
    <img src="img/PreFile6.png">
</p>

### 7.將`${Path_to_mergeFile}/output `中的`.txt`複製到`${Path_to_moss}/moss`裡

<p align="center">
    <img src="img/PreFile7.png">
</p>

### 8.點擊並執行`${Path_to_moss}/moss/getName.bat`


### 9.產生list.txt 和 file_name.txt

<p align="center">
    <img src="img/PreFile8.png">
</p>

## Usage Moss

### 1.先開啟perl

在開始搜尋"perl" -> Perl(command line)
<p align="center">
    <img src="img/perl.png", width="480">
</p>

### 2.`cd ${Path_to_moss}/moss`

### 3.`perl moss.pl -l cc [接file_name.txt中的文字]`

### 4.結果會產生一個連結
<p align="center">
    <img src="img/PreFile9.png", width="480">
</p>


