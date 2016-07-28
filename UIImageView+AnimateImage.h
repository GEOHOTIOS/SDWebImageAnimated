//
//  UIImageView+AnimateImage.h
//  SDSetAnimatedImage
//
//  Created by JobsTorvalds on 16/7/28.
//  Copyright © 2016年 JobsTorvalds. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIImageView+WebCache.h"
typedef NS_OPTIONS(NSInteger, JTWebImageOptions) {
    JTWebImageRetryFailed = 1<<0,
    JTWebImageLowPriority = 1<<1,
    JTWebImageCacheMemoryOnly = 1 << 2,
    JTWebImageProgressiveDownload = 1 << 3,
    JTWebImageRefreshCached = 1 << 4,
    JTWebImageContinueInBackground = 1 << 5,
    JTWebImageHandleCookies = 1 << 6,
    JTWebImageAllowInvalidSSLCertificates = 1 << 7,
    JTWebImageHighPriority = 1 << 8,
    JTWebImageDelayPlaceholder = 1 << 9,
    JTWebImageTransformAnimatedImage = 1 << 10,
    JTWebImageAvoidAutoSetImage = 1 << 11
};


@interface UIImageView (AnimateImage)

/*****
 *url 图片的下载地址
 */

- (void)jt_setImageWithUrl:(NSString *)url;
/***
 *url 图片的下载地址
 *placeholder 默认图片
 */

- (void)jt_setImageWithUrl:(NSString *)url placeholderImage:(UIImage *)placeholder;
/****
 *url 图片的下载地址
 *placeholder 默认图片
 *options 选项
 */

- (void)jt_setImageWithURL:(NSString *)url placeholderImage:(UIImage *)placeholder options:(JTWebImageOptions)options;
/***
 *url 图片的下载地址
 *completedBlock 下载完成后干什么事
 */


- (void)jt_setImageWithURL:(NSString *)url completed:(SDWebImageCompletionBlock)completedBlock;
/***
 *url 图片的下载地址
 *placeholder 默认图片
 *completedBlock 下载完成后干什么事
 */

- (void)jt_setImageWithURL:(NSString *)url placeholderImage:(UIImage *)placeholder completed:(SDWebImageCompletionBlock)completedBlock;
/***
 *url 图片的下载地址
 *placeholder 默认图片
 *options 选项
 *completedBlock 下载完成后干什么事
 */

- (void)jt_setImageWithURL:(NSString *)url placeholderImage:(UIImage *)placeholder options:(JTWebImageOptions)options completed:(SDWebImageCompletionBlock)completedBlock;

/****
 *url 图片的下载地址
 *placeholder 默认图片
 *animated 是否有动画
 *options 选项
 ***JTWebImageRetryFailed //失败后重试
 ***JTWebImageLowPriority //UI交互期间开始下载，导致延迟下载比如UIScrollView减速
 ***JTWebImageCacheMemoryOnly //只进行内存缓存
 ***JTWebImageProgressiveDownload //这个标志可以渐进式下载,显示的图像是逐步在下载
 ***JTWebImageRefreshCached //刷新缓存
 ***JTWebImageContinueInBackground //后台下载
 ***JTWebImageHandleCookies //存Cookie
 ***JTWebImageAllowInvalidSSLCertificates //允许无效的SSL证书
 ***JTWebImageHighPriority //优先下载
 ***JTWebImageDelayPlaceholder //延迟占位符
 ***JTWebImageTransformAnimatedImage //改变动画形象
 ***JTWebImageAvoidAutoSetImage //在图片下载完显示之前设置自动处理图片
 
 *progress 加载进度
 *completedBlock 下载完成后干什么事
 *trackTintColor 设置滑块背景颜色
 *progressTintColor 设置Progress的颜色的
 *innerTintColor 设置ProgressView的背景色
 *frame 设置ProgressView的frame
 
 */


- (void)jt_setImageWithURL:(NSString *)url placeholderImage:(UIImage *)placeholder Animated:(BOOL)animated trackTintColor:(UIColor*)trackTintColor progressTintColor:(UIColor *)progressTintColor innerTintColor:(UIColor *)innerTintColor frame:(CGRect)frame options:(JTWebImageOptions)options  progress:(SDWebImageDownloaderProgressBlock)progressBlock completed:(SDWebImageCompletionBlock)completedBlock;
/****
 *url 图片的下载地址
 *placeholder 默认图片
 *animated 是否有动画
 *options 选项
 *progress 加载进度
 *completed 下载完成后干什么事
 *trackTintColor 设置滑块背景颜色
 *progressTintColor 设置Progress的颜色的
 *innerTintColor 设置ProgressView的背景色
 *frame 设置ProgressView的frame
 注:此方法使用SDWebImage可以去加载远程图片，而且还会缓存图片，下次请求会看一下是否已经存在于缓存中，如果是的话直接取本地缓存，如果不是的话则重新请求。使用方法很简单，在需要使用该场景的类中导入
 */

- (void)jt_setImageWithPreviousCachedImageWithURL:(NSString *)url placeholderImage:(UIImage *)placeholder trackTintColor:(UIColor*)trackTintColor progressTintColor:(UIColor *)progressTintColor innerTintColor:(UIColor *)innerTintColor frame:(CGRect)frame options:(JTWebImageOptions)options Animated:(BOOL)animated progress:(SDWebImageDownloaderProgressBlock)progressBlock completed:(SDWebImageCompletionBlock)completedBlock;




@end
