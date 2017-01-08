firststhalf :: [a] -> [a]
firststhalf xs = take (n) xs
	where n = (length xs) `div` 2 

secondhalf :: [a] -> [a]
secondhalf xs = drop (n) xs
	where n = (length xs) `div` 2

merge :: (Ord a) => [a] -> [a] -> [a]
merge xs [] = xs
merge [] xs = xs
merge (x:xs) (y:ys) = case (x < y) of
	True  -> x:merge xs (y:ys)
	False -> y:merge (x:xs) ys


mergesort :: (Ord a) => [a] -> [a]
mergesort xs = case (length xs > 1) of
	True  -> merge (mergesort (firststhalf xs)) (mergesort (secondhalf xs))
	False -> xs