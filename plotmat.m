clear;

A = csvread('3D.ascii');
X = zeros(max(A(:,1))+1, max(A(:,2))+1, max(A(:,3))+1, max(A(:,4))+1);

for k = 1:size(A,1)
    ind = sub2ind(size(X), A(k,1) + 1, A(k,2) + 1, A(k,3) + 1, A(k,4) + 1);
    X(ind) = A(k,end); % +1 for matlab
end

%%
close all;

xval = linspace(-1,1,size(X,1));
yval = linspace(-1,1,size(X,2));
zval = linspace(-1,1,size(X,3));
tval = linspace( 0,1,size(X,4));

for t = 1:size(X,4)
    imagesc(yval, zval, squeeze(X(end/2,:,:,t)));
    set(gca,'YDir','normal');
    axis square;
    colormap(summer);
    drawnow;
    pause(0.3);
end

