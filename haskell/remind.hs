{-
qs [] = []
qs (x:xs) = qs smaller ++ [x] ++ qs larger
 where
  smaller = [a | a <- xs, a  <x]
  larger = [b | b <- xs, b > x]

average ns = sum ns `div` length ns

le cs = length cs
-}
--last function is from prelude
fin :: Eq k => k -> Assoc k v -> v
fin k t = head [v | (k’,v) <- t, k == k’]

