# 実験した際に作成したファイル置き場
|ファイル名|説明|備考|
|----|:---|:---|
|DebuggerDetection|デバッガでの実行を検知する(win32)<br>[ここ](https://www.mbsd.jp/research/20200910.html)を参考にした|デバッガでIsDebuggerPresent()の返り値を反転させる．|
|DebuggerDetection2|強化版．IsDebuggerPresent()に頼らず実装した．参考は↑と同じ|PEBの0x02先のアドレスにBeingDebugged(bool値)が格納されているのでそれを反転させる．↑もこれで無効化可能|
|TimeBomb|任意の時間に実行すると動作が変わる|PC内時計変更や，デバッガでの分岐変更で無効化できる．|
|EnumProcesses|プロセス名を取得する|まだ作成途中|
|test.c|angrのテスト用ファイル|パスワード認証を行うだけ|
|solve_test.py|test.cに対するangrのシンボリック実行実験|自動でパスワードをみつけてくれる|
|GFwindow.exe|アクティブなウィンドウが変動すれば活性化するプログラム||
|USB.exe|リムーバブルディスクが存在したら活性化するプログラム||