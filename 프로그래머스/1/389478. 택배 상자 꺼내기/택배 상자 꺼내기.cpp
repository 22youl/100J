#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int row = (n + w - 1) / w;
    vector<vector<int>> box(row, vector<int>(w, 0));

    // 상자 배치
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int number = i * w + j + 1;

            if (number > n)
                break;

            if (i % 2 == 0)
                box[i][j] = number;
            else
                box[i][w - 1 - j] = number;
        }
    }

    int a_row = 0;
    int a_w = 0;

    // num 위치 찾기
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (num == box[i][j])
            {
                a_row = i;
                a_w = j;
                break;
            }
        }
    }

    int answer = 1;

    // 위에 있는 상자 개수 세기
    while (a_row + 1 < row && box[a_row + 1][a_w] != 0)
    {
        answer++;
        a_row++;
    }

    return answer;
}