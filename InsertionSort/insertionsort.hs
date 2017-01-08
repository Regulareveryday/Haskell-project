insertionsort :: (Ord a) => [a] -> [a]
insertionsort xs = insert xs []



insert :: (Ord a) => [a] -> [a]-> [a]
insert [] tail     = tail
insert (x:xs) tail = insert xs sorted_tail
	where
		sorted_tail = (smaller_than_x) ++ [x] ++ (greater_or_equal_than_x)
			where
				smaller_than_x 		   = [a | a <- tail, a<x]
				greater_or_equal_than_x = [a | a <- tail, a>= x]