#pragma once

// 在头文件中定义简化宏
#define LOG_INFO(FMT, ...) UE_LOG(LogTemp, Log, TEXT(FMT), ##__VA_ARGS__)
#define LOG_WARN(FMT, ...) UE_LOG(LogTemp, Warning, TEXT(FMT), ##__VA_ARGS__)
#define LOG_ERROR(FMT, ...) UE_LOG(LogTemp, Error, TEXT(FMT), ##__VA_ARGS__)
#define LOG_FATAL(FMT, ...) UE_LOG(LogTemp, Fatal, TEXT(FMT), ##__VA_ARGS__)

// 临时消息（自动生成Key，3秒显示时间）
#define SCREEN_LOG(FMT, ...) \
do { \
if (GEngine) { \
GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::White, FString::Printf(TEXT(FMT), ##__VA_ARGS__)); \
} \
} while (0)

// 警告消息（黄色，5秒）
#define SCREEN_WARN(FMT, ...) \
do { \
if (GEngine) { \
GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT(FMT), ##__VA_ARGS__)); \
} \
} while (0)

// 错误消息（红色，10秒）
#define SCREEN_ERROR(FMT, ...) \
do { \
if (GEngine) { \
GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT(FMT), ##__VA_ARGS__)); \
} \
} while (0)
