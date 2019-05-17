namespace Test_02_retake
{
    using System.Collections.Generic;

    /// <inheritdoc />
    public class StringComparerByLength : IComparer<string>
    {
        /// <inheritdoc />
        public int Compare(string x, string y)
        {
            if (x.Length < y.Length)
            {
                return 1;
            }

            if (x.Length > y.Length)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
    }
}
