// Ionic Starter App

// angular.module is a global place for creating, registering and retrieving Angular modules
// 'starter' is the name of this angular module example (also set in a <body> attribute in index.html)
// the 2nd parameter is an array of 'requires'
// 'starter.controllers' is found in controllers.js
angular.module('starter', ['ionic', 'starter.controllers'])

.run(function($ionicPlatform, $rootScope) {
	$ionicPlatform.ready(function() {
		// Hide the accessory bar by default (remove this to show the accessory bar above the keyboard
		// for form inputs)
		if (window.cordova && window.cordova.plugins.Keyboard) {
			cordova.plugins.Keyboard.hideKeyboardAccessoryBar(true);
		}
		if (window.StatusBar) {
			// org.apache.cordova.statusbar required
			StatusBar.styleDefault();
		}
	});

	$rootScope._t=language.zh_cn;
	// $rootScope._t=language['zh_tw'];
	// $rootScope._t=language['kr'];
	// $rootScope._t = language['en'];
	// var mapurl = "http://api.map.baidu.com/staticimage?center=116.31340957014,39.989966373469&width=" + window.innerWidth + "&height=" + window.innerHeight + "&zoom=16&copyright=1&markers=车库咖啡";
	var mapurl="http://restapi.amap.com/v3/staticmap?scale=1&zoom=14&location=116.31340957014,39.989966373469&zoom=10&size="+window.innerWidth+"*"+window.innerHeight+"&markers=mid,,A:116.31340957014,39.989966373469&key=ee95e52bf08006f63fd29bcfbcf21df0";
	$rootScope.env = {
		height: window.innerHeight,
		width: window.innerWidth,
		map: mapurl
	};
})

.config(function($stateProvider, $urlRouterProvider) {
	$stateProvider

	.state('app', {
		url: "/app",
		abstract: true,
		templateUrl: "templates/menu.html",
		controller: 'AppCtrl'
	})

	.state('app.timer', {
		url: "/timer",
		views: {
			'menuContent': {
				templateUrl: "templates/timer.html",
				controller: 'timerCtrl'

			}
		}
	})

	.state('app.donate', {
		url: "/donate",
		views: {
			'menuContent': {
				templateUrl: "templates/donate.html",
				controller: 'donateCtrl'

			}
		}
	})
		.state('app.setting', {
			url: "/setting",
			views: {
				'menuContent': {
					templateUrl: "templates/setting.html",
					controller: 'PlaylistsCtrl'
				}
			}
		})

	.state('app.single', {
		url: "/setting/:playlistId",
		views: {
			'menuContent': {
				templateUrl: "templates/playlist.html",
				controller: 'PlaylistCtrl'
			}
		}
	});
	// if none of the above states are matched, use this as the fallback
	$urlRouterProvider.otherwise('/app/timer');
});