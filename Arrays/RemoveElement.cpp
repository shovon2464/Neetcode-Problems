#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int> nums, int val)
{
    int result = 0;
    int i = 0;
    while (i < nums.size())
    {
        if (nums[i] == val)
        {
            if (i != nums.size() - 1)
            {
                result++;
                int j = i + 1;
                while (true)
                {
                    if (nums[j] == val)
                    {
                        j++;
                        result++;
                    }
                    else
                    {
                        break;
                    }
                }
                int l = 0;
                for (int k = i; k < j; k++)
                {
                    nums[k] = nums[j + l];
                    l++;
                }
                i = j;
            }
            else
            {
                nums[result] = nums[i - 1];
                result++;
                break;
            }
        }
        else
        {
            i++;
        }
    }
    for (int x : nums)
    {
        cout << x << " ";
    }
    cout << endl;
    return result;
}

int main()
{

    vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
    cout << removeElement(nums, 2);
    return 0;
}