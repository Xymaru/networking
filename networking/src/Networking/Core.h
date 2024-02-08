#pragma once

#ifdef EM_BUILD_DLL
	#define EM_API __declspec(dllexport)
#else
	#define EM_API __declspec(dllimport)
#endif

#define EM_NODISCARD [[nodiscard]]

#define BIT(x) (1 << x)

#ifndef DISABLE_COPY
	#define DISABLE_COPY(T) \
		T(const T&) = delete; \
		T& operator=(const T&) = delete; 
#endif

#ifndef DISABLE_MOVE
	#define DISABLE_MOVE(T) \
		T(T&&) = delete; \
		T& operator=(T&&) = delete;
#endif

#ifndef DISABLE_MOVE_AND_COPY
#define DISABLE_MOVE_AND_COPY(T) \
			DISABLE_MOVE(T) \
			DISABLE_COPY(T) 
#endif

const size_t EM_INVALID_INDEX = static_cast<size_t>(-1);