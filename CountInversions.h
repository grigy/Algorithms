#ifndef COUNT_INVERSIONS_H
#define COUNT_INVERSIONS_H

#include <vector>

using namespace std;

long long MergeAndCountSplitInv(std::vector<int>& v, std::vector<int>& tmp, int left, int mid, int right)
{
  int i, j, k;
  long long c = 0;
  
  i = left; j = mid; k = left;

  while ((i <= mid - 1) && (j <= right))
  {
    if (v[i] <= v[j])
      tmp[k++] = v[i++];
    else 
	{
      tmp[k++] = v[j++];
      c += (mid - i);
    }
  }
  
  // copy the remaining elements
  while (i <= mid - 1)
    tmp[k++] = v[i++];

  while (j <= right)
    tmp[k++] = v[j++];
  
  // copy back into original array
  for (i=left; i <= right; i++)
    v[i] = tmp[i];
  
  return c;
}

long long SortAndCount(std::vector<int>& v, std::vector<int>& tmp, int left, int right)
{
	long long c = 0;
	if ( right > left ) 
	{
		int mid = (left + right)/2;
		c = SortAndCount(v, tmp, left, mid) + 
			SortAndCount(v, tmp, mid+1, right) + 
			MergeAndCountSplitInv(v, tmp, left, mid+1, right);
	}
	return c;
}

long long CountInversions(std::vector<int>& v) 
{
	std::vector<int> tmp(v);
	return SortAndCount(v, tmp, 0, v.size()-1);
}

#endif
