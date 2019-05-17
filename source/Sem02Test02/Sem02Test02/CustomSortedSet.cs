namespace Sem02Test02
{
    using System.Collections.Generic;

    // Б) Реализовать на его основе класс SortedSet,
    //    представляющий АТД отсортированное множество.

    public class CustomSortedSet<T>
    {
        private List<List<T>> _listsOfLists;
        private IComparer<List<T>> _listComparer;

        public CustomSortedSet(ListComparer<T> comparer)
        {
            Count = 0;
            _listsOfLists = new List<List<T>>();
            _listComparer = comparer;
        }

        public int Count { get; private set; }

        public bool Add(List<T> newListToAdd)
        {
            if (Contains(newListToAdd))
            {
                return false;
            }

            int index = 0;

            while (index < _listsOfLists.Count && _listComparer.Compare(_listsOfLists[index], newListToAdd) == 1)
            {
                index++;
            }

            _listsOfLists.Add(newListToAdd);
            Count++;
            return true;
        }

        public void Clear()
        {
            _listsOfLists = null;
            Count = 0;
        }

        public bool Contains(List<T> newList)
        {
            foreach (var existingList in _listsOfLists)
            {
                if (_listComparer.Compare(newList, existingList) == 0)
                {
                    return true;
                }
            }

            return false;
        }

        public int GetIndex(List<T> listToCheck)
        {
            var index = 0;
            foreach (var existingList in _listsOfLists)
            {
                if (_listComparer.Compare(listToCheck, existingList) == 0)
                {
                    return index;
                }

                index++;
            }

            return -1;
        }

        public bool Remove(List<T> innerListToRemove)
        {
            var indexOfInnerList = GetIndex(innerListToRemove);

            if (indexOfInnerList == -1)
            {
                return false;
            }

            _listsOfLists.RemoveAt(indexOfInnerList);
            Count--;

            return true;
        }

        public bool RemoveByIndex(int indexOfInnerList)
        {
            if (indexOfInnerList > Count)
            {
                return false;
            }

            _listsOfLists.RemoveAt(indexOfInnerList);
            Count--;
            return true;
        }

        public string GetPrinableRepresentation()
        {
            string stringToPrint = string.Empty;
            foreach (var list in _listsOfLists)
            {
                stringToPrint += list.ToString();
                stringToPrint += ", ";
            }

            return stringToPrint;
        }
    }
}
