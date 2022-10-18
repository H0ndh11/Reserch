import angr
import sys

# 解析対象の実行ファイルを指定しバイナリファイルのロード
project = angr.Project("./test00")
# バイナリファイルのエントリーポイントを現在の状態とする
state = project.factory.entry_state()
# 現在の状態からシミュレーションマネージャを構築する
simmgr = project.factory.simulation_manager(state)
# 仮想アドレスの頭" + good job"が表示されるアドレスが目標アドレスになる
find = 0x400000+0x1313
# 目標アドレスに向けて探索開始
simmgr.explore(find=find)

if simmgr.found[0]: #目標アドレスに到達する条件が見つからない場合は空になる
    found = simmgr.found[0]
    print("Solution Found!")
    # angrが入力したstdinを表示し、ファイルディスクリプタから文字列をダンプ
    print(found.posix.dumps(sys.stdin.fileno()))
else:
    print("No solutions found! :<")