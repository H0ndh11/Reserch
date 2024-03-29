import angr
import sys

p=angr.Project('./test', load_options={'auto_load_libs': False})

# test内で出現する関数のアドレス割当
# main_binからmain_objectに仕様変更.symbol.addrからsymbol.linked_addrに仕様変更
# p.loaderより、仮想アドレスの開始地点+オフセット
addr_main=p.loader.main_object.get_symbol('main').linked_addr+0x400000
addr_succeeded=p.loader.main_object.get_symbol('succeeded').linked_addr+0x400000
addr_failed=p.loader.main_object.get_symbol('failed').linked_addr+0x400000


# 上で取得したアドレスの表示
print("main = %x" % addr_main)
print("succeeded = %x" % addr_succeeded)
print("failed = %x" % addr_failed)

#main関数のアドレスを初期状態
initial_state = p.factory.blank_state(addr=addr_main)
#path->simulation_managerへ仕様変更
simmgr=p.factory.simulation_manager(initial_state)
#succeeded関数を目指し、failed関数を避けるよう指定
e=simmgr.explore(find=addr_succeeded,avoid=addr_failed)

#見つかった場合にダンプする
if simmgr.found[0]:
    found = simmgr.found[0]
    print("Solution Found!")
    print(found.posix.dumps(sys.stdin.fileno()))
else:
    print("No solutions found! :<")