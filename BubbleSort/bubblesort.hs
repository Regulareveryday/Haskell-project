bubblesort :: (Ord a) => [a] -> [a]
bubblesort xs = bubblesort_loop xs 0


bubblesort_loop :: (Ord a) => [a] -> Int -> [a]
bubblesort_loop xs i 
    | i == (length xs) = xs
    | otherwise = bubblesort_loop (bubblesort_one_iteration xs) (i + 1) 
    

bubblesort_one_iteration :: (Ord a) => [a] -> [a]
bubblesort_one_iteration (x:y:xs)
    | x > y 	= y : bubblesort_one_iteration (x:xs)
    | otherwise = x : bubblesort_one_iteration (y:xs)
bubblesort_one_iteration (x:[]) = (x:[])