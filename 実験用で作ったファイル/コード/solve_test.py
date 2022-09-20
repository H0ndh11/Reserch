import angr

p=angr.Project('./test', load_options={'auto_load_libs': False})

#test内で出現する関数のアドレス割当
addr_main=p.loader.main_bin.get_symbol('main').addr
addr_succeeded=p.loader.main_bin.get_symbol('succeeded').addr
addr_failed=p.loader.main_bin.get_symbol('failed').addr

#上で取得したアドレスの表示
print("main = %x" % addr_main)
print("succeeded = %x" % addr_succeeded)
print("failed = %x" % addr_failed)

#main関数のアドレスを初期状態
initial_state = p.factory.blank_state(addr=addr_main)
initial_path = p.factory.path(initial_state)
pg = p.factory.path_group(initial_path)
#succeeded関数を目指し、failed関数を避けるよう指定
e=pg.explore(find=(addr_succeeded,),avoid=(addr_failed,))

#見つかった場合にダンプする
if len(e.found)>0:
    print('Dump stdin at succeeded():')
    s=e.found[0].state
    print("%r" % s.posix.dumps(0))