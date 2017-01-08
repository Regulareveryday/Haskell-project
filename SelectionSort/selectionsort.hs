selectionsort :: (Ord a) => [a] -> [a]
selectionsort [] = []
selectionsort xs = minimum xs : (selectionsort tail)
                   where tail = delete (minimum xs) xs


delete :: (Eq a) => a -> [a] -> [a]
delete value [] 	= []
delete value (x:xs) = if x == value then xs else x : delete value xs