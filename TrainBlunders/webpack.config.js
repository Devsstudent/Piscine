const path = require ('path');
const BundleAnalyzerPlugin = require('webpack-bundle-analyzer').BundleAnalyzerPlugin;

module.exports = {
    entry : './src/index.js',
    output: {
        filename : 'nice.js',
        path:   path.resolve(__dirname, 'dist')
    },
    module : {
        rules: [
            {
            test: /\.scss$/,
            use: [
                'style-loader',
                'css-loader',
                'sass-loader',
            ],
        },
    ],
    },
    plugins: [
        new BundleAnalyzerPlugin()
    ]
};