﻿#include "pch.h"
#include <chrono>
#include "Component.h"

using namespace std;
using namespace winrt;
using namespace Windows::Foundation;

#ifdef _WINRT_DLL
using namespace Library::implementation;
#else
using namespace Library;
#endif

void Component::DoWork()
{
	OutputDebugString(L"Doing work");
}

hstring Component::Echo(hstring const& message)
{
	return L"Echoing: " + message;
}

IAsyncOperation<hstring> Component::EchoAsync(hstring const& message)
{
	hstring result(L"Echoing async: " + message);
	co_await 2s;
	co_return hstring(result);
}

