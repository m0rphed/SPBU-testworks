namespace Test_02_retake
{
    using System.Collections.Generic;

    /// <inheritdoc />
    public class EvenOddDigitComparer : IComparer<int>
    {
        public int Compare(int x, int y)
        {
            if (x % 2 == 0 && y % 2 != 0)
            {
                return 1;
            }
            else if (x % 2 != 0 && y % 2 == 0)
            {
                return -1;
            }
            else
            {
                if (x > y)
                {
                    return 1;
                }
                else
                {
                    return -1;
                }
            }

            return 0;
        }
    }
}
