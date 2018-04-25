functionSearch() {
  var searchPhrase = document.getElementById("searchtext");
  var mainParas = document.querySelectorAll("#main");
  var str = "";
  for (var i = 0; i < mainParas.length; i++) {
    if (mainParas[i].textContent.indexOf(searchPhrase) >= 0))
      text += "<span class = 'highlight'>" + mainParas + "</span>";
    else
      text += mainParas;
  }
}
