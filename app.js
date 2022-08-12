
class Map {
	constructor() {
		this.map = [
			[1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
			[1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
			[1, 0, 0, 0, 0, 2, 0, 0, 0, 1],
			[1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
			[1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
		];
		return this.map;
	}
}

class App {
	constructor() {
		this.canvas = document.createElement("canvas");
		document.body.appendChild(this.canvas);
		this.ctx = this.canvas.getContext('2d');
		this.pixelRatio = window.devicePixelRatio > 1 ? 2.0 : 1.0;
		this.map = new Map();
		this.player = [0, 0];
		window.addEventListener("keypress", this.keypress.bind(this));
		window.addEventListener("resize", this.resize.bind(this));
		this.resize();
		this.animate();
	}

	resize() {
		this.width = document.body.clientWidth;
		this.height = document.body.clientHeight;
		this.canvas.width = this.width;
		this.canvas.height = this.height;
	}

	animate() {
		this.ctx.clearRect(0, 0, this.width, this.height);
		this.ctx.fillStyle = '#a0b0c0';
		this.ctx.fillRect(0, 0, this.width, this.height);
		this.ctx.beginPath();
		for (let i = 0; i < this.map.length; i++) {
			for (let j = 0; j < this.map[i].length; j++) {
				if (this.map[i][j] == 1) {
					this.ctx.fillStyle = "black";
					this.ctx.fillRect(j * 32, i * 32, 30, 30);
				}
				else if (this.map[i][j] == 2) {
					this.ctx.fillStyle = "Red";
					this.ctx.fillRect(j * 32, i * 32, 30, 30);
					this.player[0] = i;
					this.player[1] = j;
				}
			}
		}
		this.ctx.closePath();
	}

	keypress(e) {
		console.log(this.player);
		this.prev = [...this.player];
		if (e.key == 'w') {
			this.player[0] -= 1;
		}
		else if (e.key == 'a') {
			this.player[1] -= 1;
		}
		else if (e.key == 's') {
			this.player[0] += 1;
		}
		else if (e.key == 'd') {
			this.player[1] += 1;
		}
		console.log(this.player, this.prev);
		if (this.map[this.player[0]][this.player[1]] != 1) {
			this.map[this.player[0]][this.player[1]] = 2;
			this.map[this.prev[0]][this.prev[1]] = 0;
		};
		this.animate();
	}
}

window.onload = () => {
	new App();
}