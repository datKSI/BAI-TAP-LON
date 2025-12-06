#ifndef LOGIC_WEATHER_H
#define LOGIC_WEATHER_H

#include <stdbool.h>

// Hàm xử lý Nắng (dùng con trỏ để thay đổi nếp, lá, thời tiết)
void handleSun(int *n, int *ld, int dc, int dg, char *weather);

// Hàm xử lý Sương mù (thay đổi kích thước bánh)
void handleFog(int *dc, int *dg, char *weather);

// Hàm kiểm tra số bạn bè (Mây)
bool checkAmicable(int n, int ld, char *weather);

#endif