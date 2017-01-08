quicksort :: (Ord a) => [a] -> [a]
quicksort []     = []
quicksort (x:xs) = (quicksort smaller) ++ [x] ++ (quicksort greater_or_equal)
    where
        smaller 		 = filter (< x) xs
        greater_or_equal = filter (>= x) xs