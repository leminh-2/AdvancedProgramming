removeIndex :: Int -> [Int] -> [Int]
removeIndex x xs | x == 0 = tail xs
                 | x == (length xs) -1 = take (length xs -1) xs
                 | otherwise = (take x xs) ++ (drop (x+1) xs)