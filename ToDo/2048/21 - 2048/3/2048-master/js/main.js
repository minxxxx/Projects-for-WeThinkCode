var grid = [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]];

function startGame() {
  grid[randomPosition()][randomPosition()] = randomNumber();
  grid[randomPosition()][randomPosition()] = randomNumber();
  console.log(grid);
  addTile();
}

window.onload = function() {
  startGame();
}

document.onkeydown = function(e) {
  
  e = e || window.event;
  
  if (e.keyCode == "38") {
    if (true === verifGrid()){
      grid[randomPosition()][randomPosition()] = randomNumber();
      addTile();
    }
    moveUp();
  } else if (e.keyCode == "40") {
    console.log(grid);
    if (true === verifGrid()){
      grid[randomPosition()][randomPosition()] = randomNumber();
      addTile();
    }
    moveDown();
  } else if (e.keyCode == "37") {
    console.log(grid);
    if (true === verifGrid()){
      grid[randomPosition()][randomPosition()] = randomNumber();
      addTile();
    }
    moveLeft();
  } else if (e.keyCode == "39") {
    if (true === verifGrid()){
      grid[randomPosition()][randomPosition()] = randomNumber();
      addTile();
    }
    moveRight();
  }
}

function verifGrid() {
  if (grid[randomPosition()][randomPosition()] == 0) {
    return true;
  } else {
    return false;
  }
}

function addTile() {

  for (var i = 0; i < grid.length; i++) {
    for(var j = 0; j < grid[i].length; j++) {
      tile = document.getElementsByClassName('grid-cell' + String(i) + String(j))[0];
      value = grid[i][j];
      tile.innerHTML = value;
      tile.className += ' value-' + value
    }
  }
}

function moveUp() {

}

function moveDown() {

}

function moveRight() {

}

function moveLeft() {

}

function mergeTiles() {
  
}

function randomPosition() {
  return Math.floor(Math.random() * grid[0].length);
}

function randomNumber() {
  return Math.random() > 0.1 ? 2 : 4;
}