function onClick() {
  for(i = 1; i < 13; i++){
	  div1 = document.createElement('div');
	  div1.style.top = 500 + (i-1);
	  div1.style.left = 500 + (i-1);
	  div1.style.width = 400 - 2*(i-1) * delta;
	  div1.style.height = 400 - (i-1 ) * delta;
	  body.appendChild(div1);
	  if(i >1)
		  div1.style.backgroundColor = (100,0,0);
	  else
		  div1.style.backgroundColor = (0,0,100);
  }
	
button1 = document.querySelector('button');
	button1.addEventListener('click', onClick);