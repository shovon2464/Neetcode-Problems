class Solution
{
public:
    int guessNumber(int n)
    {
        int left = 0;
        int right = n;

        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            int guessResult = guess(mid);
            if (guessResult == -1)
            {
                right = mid - 1;
            }
            else if (guessResult == 1)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return left;
    }
};