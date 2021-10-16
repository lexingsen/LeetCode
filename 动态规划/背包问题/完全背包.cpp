











/*
完全背包证明
自己看了y总的视频还是不太理解，想了想终于理解了。
假设遍历到第i个物体，那我们求解的就是dp[i][0],dp[i][1],…,dp[i][V]
假设现在要求的j可以分解为x + kvi, 那dp[i][j] = dp[i][x + kvi];
正常来说
dp[i][x + kvi] = max(dp[i-1][x+kvi],dp[i-1][x+(k-1)vi] + wi,.., dp[i-1][x] + kwi)
那么同理
dp[i][x + (k-1)vi] = max(dp[i-1][x+(k-1)vi],.., dp[i-1][x] + （k-1）wi)
又
dp[i][x + kvi] = max(dp[i-1][x+kvi],max(dp[i-1][x+(k-1)vi] + wi,.., dp[i-1][x] + k*wi))

max(dp[i-1][x+(k-1)vi] + wi,.., dp[i-1][x] + kwi) = dp[i][x + (k-1)*vi] + wi

所以 推出
dp[i][x + k * vi] = max(dp[i-1][x + kvi],wi + dp[i][x + (k-1)vi])
所以
dp[i][j] = max(dp[i-1][j], wi + dp[i][j-vi])
把i去掉
dp[j] = max(dp[j],dp[i][j-vi] + wi)

所以必须从后往前遍历，因为 要求数组index >= 0, j - vi >= 0 -> j >= vi, j从vi开始遍历
*/