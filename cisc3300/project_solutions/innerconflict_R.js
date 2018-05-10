
 container = document.querySelectorAll('div');
  for(i=1;i<container.length;i++) {
      ii = Math.floor(Math.random()*255);
jj= Math.floor(Math.random()*255);
kk= Math.floor(Math.random()*255);
     console.log( ii,"  ",jj,"   ",kk);
     container[i].style.backgroundColor = (ii,jj,kk);
          }