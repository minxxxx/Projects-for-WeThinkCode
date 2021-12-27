module.exports = function(grunt) {

	// Project configuration.
	grunt.initConfig({
		pkg: grunt.file.readJSON('package.json'),
		// 压缩JavaScript
		uglify: {
			options: {
				banner: '/*! <%= pkg.name %> <%= grunt.template.today("yyyy-mm-dd") %> */\n',
				mangle: false
			},
			buildApp: {
				src: 'src/js/app.js',
				dest: 'build/js/app.js'
			},
			buildControllers: {
				src: 'src/js/controllers.js',
				dest: 'build/js/controllers.js'
			},

			buildServices: {
				src: 'src/js/services.js',
				dest: 'build/js/services.js'
			},
			buildGlobal: {
				src: 'src/js/global.js',
				dest: 'build/js/global.js'
			},
			buildAll: {
				src: 'src/js/*.js',
				dest: 'build/js/mainJS.js'
			}
		},
		// 压缩CSS
		cssmin: {
			options: {
				keepSpecialComments: 0
			},
			compressCSS: {
				files: {
					'build/css/style.css': [
						"src/css/style.css"
					],
					'build/lib/ionic/css/ionic.css':[
						'src/lib/ionic/css/ionic.css'
					]
				}
			}
		},
		// 检查错误
		jshint: {
			all: ["src/js/app.js", "src/js/controllers.js",
				"src/js/services.js","src/js/global.js"
			]
		},
		// 复制文件到开发目录
		copy: {
			main: {
				files: [{
					expand: true,
					cwd: 'src/',
					src: ['**'],
					dest: 'build/'
				}]
			}
		},
		// 混淆函数名字
		shell: {
			exportFixRateData: {
				command: 'python ./tool/nameConfound.py',
				options: {
					async: false,
					stdout: true
				}
			}
		},
		// sftp上传压缩后文件到测试服务器
		sftp: {
			test: {
				files: {
					"./": "build/**/*"
				},
				options: {
					path: '/home/html5/42run/',
					srcBasePath: "build/",
					host: '<%= pkg.host %>',
					username: '<%= pkg.username %>',
					password: '<%= pkg.password %>',
					showProgress: true,
					createDirectories: true
				}
			}
		},
		// 压缩html
		htmlmin: {
			dist: {
				options: {
					removeComments: true,
					collapseWhitespace: true
				},
				files: {
					'build/index.html': 'src/index.html',
					// 'build/config.xml': 'src/config.xml',
					'build/templates/donate.html': 'src/templates/donate.html',
					'build/templates/login.html': 'src/templates/login.html',
					'build/templates/menu.html': 'src/templates/menu.html',
					'build/templates/playlist.html': 'src/templates/playlist.html',
					'build/templates/setting.html': 'src/templates/setting.html',
					'build/templates/timer.html': 'src/templates/timer.html'
				}
			}
		}
	});

	// 导入插件
	grunt.loadNpmTasks('grunt-contrib-uglify');
	// grunt.loadNpmTasks('grunt-contrib-watch');
	// grunt.loadNpmTasks('grunt-contrib-concat');
	grunt.loadNpmTasks('grunt-contrib-cssmin');
	grunt.loadNpmTasks('grunt-contrib-jshint');
	grunt.loadNpmTasks('grunt-contrib-htmlmin');
	grunt.loadNpmTasks('grunt-contrib-copy');
	grunt.loadNpmTasks('grunt-shell');
	grunt.loadNpmTasks('grunt-ssh');



	// 默认任务
	grunt.registerTask('default', ["jshint", "copy", "htmlmin",
		"uglify:buildApp", "uglify:buildControllers",
		"uglify:buildServices","uglify:buildGlobal", "cssmin", "shell","sftp"
	]);
	grunt.registerTask('miniall', ["uglify:buildall"]);


};