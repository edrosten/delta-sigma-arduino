./delta_sigma > s

#Postprocess to make a prettier output.
awk '
{
	if(p != $2)
		print NR, p
}

{	
	print NR, $2
	p=$2;
}' s > t;


plot -ps="eps color enhanced 14"  t spec="with lines lw 2 notitle"  s spec="using 1 with lines lw 4 notitle" > graph.eps
gv graph.eps
