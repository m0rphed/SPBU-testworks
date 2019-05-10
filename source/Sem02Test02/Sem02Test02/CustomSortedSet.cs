namespace Sem02Test02
{
    using System;
    using System.Collections;
    using System.Collections.Generic;

    // б) Реализовать на его основе класс SortedSet,
    // представляющий АТД отсортированное множество.

    public class CustomSortedSet<T>
    {
        private List<T> _setValues = null;

        public static void Swap<T>(IList<T> list, int indexA, int indexB)
        {
            T tmp = list[indexA];
            list[indexA] = list[indexB];
            list[indexB] = tmp;
        }

        public CustomSortedSet(IComparer<T> comparer)
        {
            Count = 0;
        }

        public int Count { get; private set; }

        public bool Add(T item)
        {
            if (Contains(item))
            {
                return false;
            }
            else
            {
                _setValues.Add(item);
                Count++;

                int index = Count - 1;
                while (Comparer<T>.Default.Compare(_setValues[index], _setValues[index - 1]) == 1)
                {
                    Swap(_setValues, index, index - 1);
                }

                return true;
            }
        }

        public void Clear()
        {
            _setValues = null;
        }

        public bool Contains(T item)
        {
            foreach (T value in _setValues)
            {
                if (Comparer<T>.Default.Compare(item, value) == 0)
                {
                    return true;
                }
            }

            return false;
        }

        public int GetIndexByValue(T valueToCheck)
        {
            var index = 0;
            foreach (T value in _setValues)
            {
                if (Comparer<T>.Default.Compare(valueToCheck, value) == 0)
                {
                    return index;
                }

                index++;
            }

            return -1;
        }

        public bool Remove(T item)
        {
            Fo
        }
    }
}
