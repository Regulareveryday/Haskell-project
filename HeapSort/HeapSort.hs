{-|
Module      : HeapSort
Description : heapsort implemented in Haskell language
Copyright   : (c) Julia Sypień, Patrycja Tarasińska, 2017
License     : GPL-3
Maintainer  : sasuke96@tlen.pl
Stability   : experimental
Portability : POSIX
-}

module HeapSort(
parent,
leftChild,
rightChild,
heapify,
buildHeap,
myInit,
heapSortLoop,
heapSort
)where

parent :: (Integral a, Num a, Ord a) => a -> a-- |Function which takes index of a cell in a talbe and returns its parent
parent a =
   if a <= 0 
      then (-1)
      else (a - 1) `div` 2

	
leftChild :: (Num a) => a -> a-- |Function which takes index of a cell in a talbe and returns its left child
leftChild a = 2*a + 1

rightChild :: (Num a) => a -> a-- |Function which takes index of a cell in a talbe and returns its right child
rightChild a = 2*a + 2
			   


heapify :: (Ord a) => [a] -> Int -> [a]-- |Function which restores a heap condition in a node
heapify [] _ = []
heapify xs a =
   if a < 0 
      then []
      else if((leftChild a) < length xs && xs!!(leftChild a) > xs!!a && ((rightChild a) >= length xs || xs!!(rightChild a) <= xs!!(leftChild a)))
         then heapify ((take a xs)++xs!!(leftChild a):(drop (a+1) (take (leftChild a) xs))++xs!!a:(drop ((leftChild a) + 1) xs)) (leftChild a) 
      else if((rightChild a) < length xs && xs!!(rightChild a) > xs!!a)
         then heapify ((take a xs)++xs!!(rightChild a):(drop (a+1) (take (rightChild a) xs))++xs!!a:(drop ((rightChild a) + 1) xs)) (rightChild a) 
         else xs
		 


buildHeap :: (Ord a) => [a] -> Int -> [a] -- |Function which creates a heap out of a table
buildHeap [] _ = []
buildHeap xs i =
    if(i < 0) 
        then xs
    else if (leftChild i) >= length xs
        then buildHeap xs (i-1)
    else buildHeap (heapify xs i) (i-1)
	

heapSortLoop :: (Ord a) => [a] -> Int ->[a]-- |Function which is a part of sorting algorithm
heapSortLoop [] _ = []
heapSortLoop xs result = 
   if(result == 0)
      then xs
   else heapSortLoop ((heapify (xs!!result : tail (take result xs)) 0)++ xs!!0:(drop (result+1) xs)) (result - 1)
   
heapSort :: (Ord a) => [a] -> [a]-- |Function which sorts elements in a table by using heapsort algorithm
heapSort [] = []
heapSort xs = heapSortLoop  (buildHeap xs ((length xs) - 1)) ((length xs) - 1)
   
