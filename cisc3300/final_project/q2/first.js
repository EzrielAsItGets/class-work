function highlightSearch() {
    var keyword = document.getElementById("searchtext").value;
    var highlight = new RegExp("(\\b" + keyword + "\\b)", "gim");
    var paragraph = document.getElementById("main").innerHTML;
    var paragraphnew = paragraph.replace(/(<span>|<\/span>)/igm, "");
    document.getElementById("main").innerHTML = paragraphnew;
    var newparagraph = paragraphnew.replace(highlight, "<span>$1</span>");
    document.getElementById("main").innerHTML = newparagraph;
}
