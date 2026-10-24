# TVTest-22.2ch-Renderer-ver-

8Kの22.2ch番組をダウンミックスもしくは<br>
Dolby atmos、windows sonic for headphonesにて再生できるようにしたものです。

## 【前提】<br>
22.2chを利用する方はtvtestー音声ーAACデコーダは <ins>**Fraunhofer FDK AAC(3.2.0)**</ins>　を選択

## 【使用方法】<br>
（１）bondriver_dantto4K.iniに<br>
　　　disableADTSConversion=　の記述がある場合<br>
　　　；（セミコロン）、行ごと削除、falseの記載　をすることで22.2chの再生が可能になります。<br><br>
   
（２）tvtestを開き、音声ー22.2ch音声のダウンミックスーダウンミックスから選択<br><br>
　　　※手軽に22.2chを楽しみたい場合は　<ins>**ダウンミックスを行わない**</ins>　を選択したうえで<br>
　　　サウンド設定からwindows sonic for headphonesにすることで楽しめます。<br>
　　　（Dolby atmos環境の方も同じ）<br><br>
　　　Dolby atmos環境がない方でスピーカーやサラウンドヘッドホンにて楽しみたい方は<br>
　　　7.1chや5.1ch、2chを選択。<br><br>
   
## その他<br>
再生中にダウンミックスの項目を触った場合、フィルタグラフを再初期化をすることをオススメいたします。<br>
※特に録画ファイルをtvtplayにて再生していると映像と音声にズレる場合があるため。<br><br><br>
【課題】<br>
22.2音声のダウンミックス項目内の<br>
出力方式およびプリセットの運用方法について<br>
（利用者のスピーカー構成は様々であり、かつスピーカーの配置も異なるため検討中）<br><br>
<img width="576" height="567" alt="github説明" src="https://github.com/user-attachments/assets/344363de-3bb5-43a8-ad13-b00d98575aaa" />





---

デジタル放送汎用視聴プログラム実装研究資料
==========================================
デジタル放送汎用視聴プログラム実装研究資料(略称 TVTest)は、パーソナルコンピュータ上において、デジタル放送の視聴を行うプログラムの実装を研究する目的で頒布される研究資料です。

この資料は MPEG-2 TS を扱うための基本的な機能を実装しています。  
CAS 処理は実装されていないため、一般のテレビ放送を視聴することはできません。


依存ライブラリ
--------------
* [DirectShow BaseClasses](https://github.com/Microsoft/Windows-classic-samples/tree/master/Samples/Win7Samples/multimedia/directshow/baseclasses)
* [Fraunhofer FDK AAC](https://github.com/mstorsjo/fdk-aac)
* [FAAD2](https://github.com/knik0/faad2)
* [libmad](http://www.underbit.com/products/mad/)
* [liba52](http://liba52.sourceforge.net/)
* [libjpeg](http://www.ijg.org/)
* [libpng](http://libpng.org/)
* [zlib](http://zlib.net/)


ライセンス
----------
GNU General Public License v2.0 or later (GPL-2.0-or-later)
