namespace Test_02_retake
{
    using System;
    using System.Collections.Generic;

    public class BubbleSort
    {
        /// <summary>
        /// Generic method for "Bubble sorting" a list of items.
        /// </summary>
        /// <typeparam name="T">Any type, for example, int, double, etc.</typeparam>
        /// <param name="list">A list of items.</param>
        /// <param name="comparer">Comparer object.</param>
        public static void BubbleSortWithComparer<T>(List<T> list, IComparer<T> comparer)
            where T : IComparable
        {
            for (int outer = list.Count; outer >= 1; outer--)
            {
                for (int inner = 0; inner < outer - 1; inner++)
                {
                    if (comparer.Compare(list[inner], list[inner + 1]) > 0)
                    {
                        T swap = list[inner];
                        list[inner] = list[inner + 1];
                        list[inner + 1] = swap;
                    }
                }
            }
        }
    }
}
