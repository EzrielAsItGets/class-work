functionSearch() {
  var searchPhrase = document.getElementById('searchtext');
  var mainParas = document.querySelectorAll('#main');
  for (var i = 0; i < mainParas.length; i++) {
    mainParas[i].textContent.indexOf(searchPhrase) >= 0);
  }
  $('#main:contains(searchPhrase)').setAttribute('class', 'highlight');
}
