# 実験した際に作成したファイル置き場
|ファイル名(cpp, exe)|説明|対策|
|----|:---|:---|
|DebuggerDetection|デバッガでの実行を検知する(win32)<br>[ここ](https://www.mbsd.jp/research/20200910.html)を参考にした|デバッガでIsDebuggerPresent()の返り値を反転させる．|
|DebuggerDetection2|強化版．IsDebuggerPresent()に頼らず実装した．参考は↑と同じ|PEBの0x02先のアドレスにBeingDebugged(bool値)が格納されているのでそれを反転させる．↑もこれで無効化可能|
|TimeBomb|任意の時間に実行すると動作が変わる||