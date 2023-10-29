#include <windows.h>
#include <chrono>
#include <ctime>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	//現在時刻の取得
	auto now = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(now);       //std::time_t型に変換
	std::tm local_time;														//結果の格納場所
	localtime_s(&local_time, &end_time);									//std::tm型に変換

	//8月26日に起動
	if (local_time.tm_mon == 7 && local_time.tm_mday == 26) {
		MessageBox(NULL, TEXT("マルウェアが活性化しました"), TEXT("Time of Attack!"), MB_OK | MB_ICONERROR);
	}

	return 0;
}