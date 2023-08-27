--ch4.pdf
--safetail :: [a] -> [a]
--conditional expression
--safetail xs = if xs == [] then [] else tail xs

--guared equations
--safetail xs | xs==[] = []
--			  | otherwise = tail xs

--pattern matching
safetail :: [a] -> [a]
safetail [] = []
safetail xs = tail xs

--question 2
ands :: Bool -> Bool -> Bool

True `ands` b = b
--other ways: ands True b = b, this principle is the same when running cmd
False `ands` _ = False


--question 3
andy :: Bool -> Bool -> Bool
andy a b = if (a==True && b==True) then True
          else False

--question 4
andi :: Bool -> Bool -> Bool
andi a b = if a==True then b
	else if a==False then False else False