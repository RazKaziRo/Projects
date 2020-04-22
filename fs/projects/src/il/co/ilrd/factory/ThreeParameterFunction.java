package il.co.ilrd.factory;

@FunctionalInterface
public interface ThreeParameterFunction<U, V, W, R> {
    public R apply(U u, V v, W w);
}
